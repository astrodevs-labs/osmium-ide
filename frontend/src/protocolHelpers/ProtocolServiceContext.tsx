import ProtocolConnector from "./ProtocolConnector";
import {createContext, useContext, useRef, useState, ReactNode, useEffect} from "react";

export const ProtocolServiceContext = createContext<ProtocolConnector>(new ProtocolConnector("ws://echo.websocket.events"));

const ProtocolServiceProvider = ({ children }: { children?: ReactNode}) => {
  return (
    <ProtocolServiceContext.Provider value={new ProtocolConnector("ws://echo.websocket.events")}>
      {children}
    </ProtocolServiceContext.Provider>
  );
};

export const useProtocolService = () => useContext(ProtocolServiceContext);

export default ProtocolServiceProvider;
