import {Component} from "./Component";
import {useProtocolService} from "./ProtocolServiceContext";
import {useEffect, useState} from "react";
import {Message} from "./Message";

export function useInitialQuery(): Component | null {
  const protocolService = useProtocolService()!;
  const [components, setComponents] = useState<Component | null>(null);

  useEffect(() => {
    const subscription = protocolService.onMessage((data: Message) => {
      if (data.type === "initialQueryResponse") {
        setComponents(data.components);
      }
    });
    protocolService.send({type: "initialQuery"})
    return () => subscription.unsubscribe();
  }, [protocolService]);

  return components;
}