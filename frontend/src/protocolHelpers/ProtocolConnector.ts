import {Subject, Subscription} from "rxjs";
import { Message } from "./Message";

export default class ProtocolConnector {
  private _webSocket: WebSocket;
  private _toSend: string[] = [];
  private _onMessageSubject = new Subject<string>();
  private _onMessageObservable = this._onMessageSubject.asObservable();

  constructor(url: string) {
    this._webSocket = new WebSocket(url);
    this._onopen();
    this._onmessage();
  }

  private _onopen() {
    this._webSocket.onopen = () => {
      console.log(`ProtocolConnector onopen`);
      this._toSend.forEach(data => this._webSocket.send(data));
    }
  }

  private _onmessage() {
    this._webSocket.onmessage = (event) => {
      console.log(`ProtocolConnector onmessage`);
      this._onMessageSubject.next(event.data);
    }
  }

  public send(data: any): void {
    const dataString = JSON.stringify(data);
    if (this._webSocket.readyState === WebSocket.OPEN) {
      this._webSocket.send(dataString);
    } else {
      this._toSend.push(dataString);
    }
  }

  public onMessage(callback: (data: Message) => void): Subscription {
    return this._onMessageObservable.subscribe(callback);
  }
}