import { useEffect } from "react";
import { useProtocolService } from "./ProtocolServiceContext";
import { Component } from "./Component";
import {Message} from "./Message";

export function useComponentUpdated(clbk: (parentId: string, component: Component) => void): void {
    const protocolService = useProtocolService();

    useEffect(() => {
        const subscription = protocolService.onMessage((data: Message) => {
            if (data.type === "componentUpdated") {
                clbk(data.parentId, data.component);
            }
        });
        return () => subscription.unsubscribe();
    });
}