import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ArduinoAppComponent } from './arduino-app.component';

describe('ArduinoAppComponent', () => {
  let component: ArduinoAppComponent;
  let fixture: ComponentFixture<ArduinoAppComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ArduinoAppComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ArduinoAppComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
