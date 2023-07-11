import ProtocolConnector from "./ProtocolConnector";
import {createContext, useContext, useRef, useState, ReactNode, useEffect} from "react";

export const ProtocolServiceContext = createContext<ProtocolConnector | null>(null);

const ProtocolServiceProvider = ({ children }: { children?: ReactNode}) => {
  return (
    <ProtocolServiceContext.Provider value={new ProtocolConnector("ws://127.0.0.1:9001")}>
      {children}
    </ProtocolServiceContext.Provider>
  );
};

export const useProtocolService = () => useContext(ProtocolServiceContext);

export default ProtocolServiceProvider;
