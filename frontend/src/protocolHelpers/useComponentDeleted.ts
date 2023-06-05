import { useEffect } from "react";
import { useProtocolService } from "./ProtocolServiceContext";
import { ComponentId } from "./Component";
import {Message} from "./Message";

export function useComponentDeleted(clbk: (parentId: string, componentId: ComponentId) => void): void {
    const protocolService = useProtocolService();

    useEffect(() => {
        const subscription = protocolService.onMessage((data: Message) => {
            if (data.type === "componentDeleted") {
                clbk(data.parentId, data.componentId);
            }
        });
        return () => subscription.unsubscribe();
    });
}

/*
    usage:
        useComponentDeleted("componentId", () => {
            console.log(props);
        }
*/