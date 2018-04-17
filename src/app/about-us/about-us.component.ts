import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-about-us',
  templateUrl: './about-us.component.html',
  styleUrls: ['./about-us.component.css']
})
export class AboutUsComponent implements OnInit {

  public map = true;
  public show = true;
  constructor() { }

  ngOnInit() {
  }

onClick() {
  this.map = !this.map;
  
}

onClickImage() {
  this.show = !this.show
}

}
