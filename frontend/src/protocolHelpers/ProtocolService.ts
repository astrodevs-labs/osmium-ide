import { Subscription } from "rxjs";
import ProtocolConnector from "./ProtocolConnector";
import { Message } from "./Message";

export default class ProtocolService {
    private _connector;

    constructor(host: string = "ws://localhost", port: number = 8080) {
        this._connector = new ProtocolConnector(`${host}:${port}`);
    }

    public onMessage(callback: (data: Message) => void): Subscription {
        return this._connector.onMessage(callback);
    }
    
    public sendInitialQuery(): void {
        this._connector.send({type: "initialRequest"});
    }

    public sendComponentInteracted(componentId: string, interactionType: string): void {
        this._connector.send({
            type: "componentInteracted", 
            componentId, 
            interactionType
        });
    }

}