# makathon2018
kaist global makers League, bronze maker

## 구현 목표
* 2박 3일 기간동안 (무박아님) 움직일 수 있는 워킹프로토타입을 시제 제작이 목표

* 구현 아이템

  - IOT 스마트 주전자
![시제품 예상 이미지1](https://github.com/moonchanyong/makathon2018/blob/master/imgs/home1.jpg?raw=true)
![시제품 예상 이미지2](https://github.com/moonchanyong/makathon2018/blob/master/imgs/home2.jpg?raw=true)
  - 구현 기능
  + 알렉사를 통한 음성제어 (라즈베리 파이 이용)
  + 카트리지 4개 장착 후 분말 타입의 음료를(커피,홍차 등) 사용자 요청에 의해  주전자가 나오면 따로 제공
  + 기울기센서를 이용해서 한번의 명령에 한번씩이 아니라 개수를 같이 명령
## 구현
  * 구현 상세
  + 아두이노
  ![아두이노 레이아웃](https://github.com/moonchanyong/makathon2018/blob/master/imgs/rayout.png?raw=true)
  각 기능을 하는 함수 들을 제공하여 시리얼로 입력된 명령을 수행, route로 분기를 일으키게 하고, 음료를 명령하고 실제로 물을 따르지 않았을경우 예외처리 등
  + 라즈베리파이
  nodejs 서버를 이용, 서버에 request가 오면 아두이노에 serial port에 명령 전달
  + App
  시간제한으로 빠르게 만들기위해 웹앱기반 하이브리드 앱으로 제작
  그리고 heroku 서버에 올려서 웹에서 앱을 받아서 사용하게 만듬

  * Truoble Shooting

  - 알렉사
  1. 환경 세팅으로 충돌
  알렉사를 이용하여 제품을 제어하는것이 사실 최고 목표라고 생각 하였으나, 라즈베리파이가 미리 세팅된 환경설정과 충돌나서 환경을 고치고, 알렉사 베이스 앱에서 포트등을 바꿔주면서 해결하였으나 결국 조금씩 고치면 원초적 문제가 해결이 안되서 라즈베리파이 초기화하여 처음부터 진행
  2. 블루투스 스피커
  블루투스 모듈등을 다운바당 스피커와 페어링까지는 가능한데 스피커에서 사용하는 pulse audio와 라즈베리와 다른지 스피커에서는 제대로 소리가 출력이 안됨
  이 부분은 다음문제 때문에 해결을 못 함
  3. SD메모리
  10시 끝나고 집가려고 짐을 싸다가 라즈베리파이 다시 케이스에 넣는데 잘못해서 sd카드 핀 부분 손상. 저녁 11시에 sd메모리 카드 파는곳이 없어서 계획 변경으로 급하게 웹앱으로 변경하여 제작

  - 라즈베리 파이 및 webapp
  1. 라즈베리의 노드서버는 로컬 서버
  라즈베리는 로컬서버라 같은망에서 ip로 송수신을 해야하는데, 처음 앱을 구상할때 SPA형식이라 처음 로드시 다 받아와서 앱은 현재 내가 브라우저로 앱을 구동한 디바이스에 있으므로 지금 사용하는 환경에서 하드코딩한 ip 주소로 request를 보내면 될거라고 생각 .. 하지만 문제는 polyfill로 변경된 angular Http 에서 request가 노드 서버에서 받을 수 가없어서 이것은 로컬 망에서 request를주는것이 아니라고 판단 시간이 얼마 없어서 바로 로컬 브라우저에서request를 주도록 하드코딩 후 해결

  - 아두이노
  1. 아두이노 잘못된 정보
  같은 팀의 1학년인 팀원이 아두이노 스태퍼모터는 동시에 제어가 안되는 구조라고 블로그에 되있어서 지금 스태퍼 모터가 안된다는 말에 진동만 하는 스태퍼 모터를 보여줘서 아두이노는 단일스레드라고 추측햇던 아두이노가 단일스레드가 아니라서 혹시 스태퍼 모터 하나가 실행되고 있으면 다른 스태퍼 모터는 이미 스태퍼 모터에 필요한 자원을 사용하고잇어서 못사용하나 착각
  => 아두이노 코드를 직접 코딩 하면서 우선 아두이노 체계를 검색햇는데 추측한대로 단일스레드 기반, 예전에 freertos로 구현해본 경험이 있어서 생각보다 스케쥴링되면서 원하는 기능을 구현하게 한는것은 어렵지 않았다.
  2. 스태퍼모터가 안되는이유
  스태퍼 모터가 안됫던이유는 setSpeed 설정에서 모터 속도를 60을 놓아서 그랬는데 아두이노를 핀을 꽂은 환경을보니 5v엿고, 인터넷에서 수집한 정보에 따르면 7v 에서 38이 최고인데 5v에서 60을 바래서 무리가 있어서 speed를 변경(기능 구현상 문제없음)

  - 디자인
  1. 적은 시행착오 횟수
  3d프리터를 이용해 뽑아서 제작하다보니 제한된 시간에 모든 제품을 이루는 부품을 뽑을시간도 없었고(무박이 아님)그래서 부품을 뽑아서 맞추는순간 조금씩 엇나가는걸 깨닫고 실제로 모터가 구동하면 다른 부분에 필요한 결함등이 순조로운 기능 구현등에 문제가 있는걸 깨달았다. 이부분은 새로운 부품으로 대체하거나 해야했지만 나중에 투표전에 현제 우리가 만든 제품이 비쥬얼적으로 많은것을 보여줄 수없다고 생각하여 만든 제품을 하울의 움직이는 성처럼 기괴하게 움직이게해놓고 투표하게 할까라고 생각했지만 애초에 그렇게 제작이 되지않아서 중심을 못잡아서, 기계적인 부분을 보여주고싶어서 겉 부분을 다 제거하고 실제로 움직이는 래크 부품에 꽃을달아서 투표할때 시선을 끌도록 해놓았다. => 신의한수


## 느낀점

개인적으로는 최고로 재밌는 대회였다. 소프트웨어 적인 부분을 거의 혼자 다 맡고있어서 이 부분을 하면서 예전에 했던 경험들이 사용됫는데 생각보다 쓸만 한 경험들이 있는것을 깨달았다.

아두이노 - 임베디드 Ubrain의  freertos를 이용한 스케쥴링에서 아두이노의 단일쓰레드 루프처럼 동작

라즈베리파이 - 간단하게 리퀘스트를 받으면 아두이노로 제어를 전송하는 노드서버 , 굳이 구현까지는 아니고 너무 간단한게 구현 했지만 예전에 잠깐 노드로 무엇인가를 만들어보려는 경험이 있어서 쉽게 할 수 있었다. 하지만 좀 더 서버쪽 능력이 커졋으면 하는 니즈가 생겼다 .(실제로 규모가 있는 서버를 구현 해 본적이 없는것같다)

app - 현재 하고있는 상용화를 생각하는 ionic app은 우선 프로토 타입으로 만들기에 디자인적 요소는 안들어가도되고 웹기술을 사용해서 어렵지 않았다..

진짜 내가 할 수 있는게 어느정도인지 체크하는 대회 같아서 개인적으로 재밌었고, 알렉사를 넣었어야햇는데라는 후회가 계속 밀려온다.. 알렉사만 넣었어도 .. 알렉사만...어려운게 아닌데 문제의 문제가 계속 터지고...