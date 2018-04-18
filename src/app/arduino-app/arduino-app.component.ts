import {
    Component,
    OnInit
} from '@angular/core';
import {
    PubNubAngular
} from 'pubnub-angular2';

@Component({
    selector: 'app-arduino-app',
    templateUrl: './arduino-app.component.html',
    styleUrls: ['./arduino-app.component.css'],
    providers: [PubNubAngular]
})
export class ArduinoAppComponent implements OnInit {

    public appStart = true;
    public myMessage;
    public history;
    // public history;



    // CREATING MODEL FOR USER INPUT
    model = {
        firstname: "",
        lastname: "",
        history: ""
    }


    constructor(pubnub: PubNubAngular) {


        // LINKJ TO PUBNUB
        pubnub.init({
            publishKey: 'pub-c-f1bdab1f-6f75-45fc-8766-3eae32fb8e97',
            subscribeKey: 'sub-c-85c498f4-3667-11e8-8741-e2a40c21c595'
        })
        pubnub.subscribe({
            channels: ['jChannel'],
            triggerEvents: true,
            withPresence: true,

        })
        // CREATE PUBNUB HISTORY

        pubnub.history({
                channel: 'jChannel',

                reverse: false, // false is the default
                count: 10, // 100 is the default
                stringifiedTimeToken: true
                // false is the default
            },

          function(status, response) {
                // LOG HISTORY TO CONSOLE


                console.log("History Below: ")
                console.log(response.messages)
            }

        )



        // TAKE LIVE DATA FROM PUBNUB
        this.myMessage = pubnub.getMessage('jChannel', (msg) => {
            // console.log(this.myMessage[this.myMessage.length -1].message.Letter[0]);
        })


    }

    ngOnInit() {}

    onEnter() {
        this.appStart = !this.appStart;
    }


}
