import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import './styles.css';
import ProtocolServiceProvider from "./protocolHelpers/ProtocolServiceContext";

ReactDOM.createRoot(document.getElementById('root') as HTMLElement).render(
  <React.StrictMode>
    <ProtocolServiceProvider>
      <App />
    </ProtocolServiceProvider>
  </React.StrictMode>,
);
