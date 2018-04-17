import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import {RouterModule} from '@angular/router';
import {FormsModule} from '@angular/forms';
import {ReactiveFormsModule} from '@angular/forms';

import { AppComponent } from './app.component';
import { HomeInfoComponent } from './home-info/home-info.component';
import { NavbarComponent } from './navbar/navbar.component';
import { ArduinoAppComponent } from './arduino-app/arduino-app.component';
import { AboutUsComponent } from './about-us/about-us.component';




@NgModule({
  declarations: [
    AppComponent,
    HomeInfoComponent,
    NavbarComponent,
    ArduinoAppComponent,
    AboutUsComponent,


  ],
  imports: [
    BrowserModule,
    FormsModule,
    ReactiveFormsModule,
    RouterModule.forRoot([
      { path: '', component: HomeInfoComponent },
      { path: 'about', component: AboutUsComponent },
      { path: 'arduino', component: ArduinoAppComponent },



    ])
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
