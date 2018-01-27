import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { Http, Headers } from '@angular/http';
/**
 * Generated class for the OrderPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@IonicPage()
@Component({
  selector: 'page-order',
  templateUrl: 'order.html',
})
export class OrderPage {
  cartridge: number ;
  cups: number
  constructor(public navCtrl: NavController, public navParams: NavParams,
    public http: Http) {
  }

  push_(){
    // this.http.get('http://192.168.0.121:5000/' + this.cups  + this.cartridge).subscribe(data =>{
    //   console.log(data);
    // });
    // console.log('http://192.168.0.121:5000/' + this.cups  + this.cartridge);
    let mywind = window.open('http://192.168.0.121:5000/' + this.cups  + this.cartridge)
    setTimeout(function() {
      mywind.close();
    }, 400);

  }

  ionViewDidLoad() {
    console.log('ionViewDidLoad OrderPage');
  }

}
