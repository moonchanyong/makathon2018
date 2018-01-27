import { NgModule } from '@angular/core';
import { IonicPageModule } from 'ionic-angular';
import { CartridgesPage } from './cartridges';

@NgModule({
  declarations: [
    CartridgesPage,
  ],
  imports: [
    IonicPageModule.forChild(CartridgesPage),
  ],
})
export class CartridgesPageModule {}
