import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';

/**
 * Generated class for the CartridgesPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@IonicPage()
@Component({
  selector: 'page-cartridges',
  templateUrl: 'cartridges.html',
})
export class CartridgesPage {
  items: Array<string> = ["../assets/imgs/giphy.gif","../assets/imgs/gi.gif","../assets/imgs/gip.gif"]
  constructor(public navCtrl: NavController, public navParams: NavParams) {
  }

  ionViewDidLoad() {
    console.log('ionViewDidLoad CartridgesPage');
  }

}
