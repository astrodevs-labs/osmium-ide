import { appWindow } from '@tauri-apps/api/window';
import ComponentsBuilder from './builder/ComponentsBuilder';
// import { tree, tree2, tree3 } from './tree';
import { useInitialQuery } from './protocolHelpers/useInitialQuery';
import { useState } from 'react';
import { Component } from './protocolHelpers/Component';

const App = () => {
  const tree = useInitialQuery();
  console.log("tree" + tree);
  const minimize = async () => {
    await appWindow.minimize();
  };

  const maximize = async () => {
    appWindow.isMaximized().then((maximized) => {
      if (maximized) {
        appWindow.unmaximize();
      } else {
        appWindow.maximize();
      }
    });
  };

  const close = async () => {
    await appWindow.close();
  };

  return (
    <div className="h-full w-full">
      <div data-tauri-drag-region className="titlebar">
        <div className="titlebar-title">OsmiumIDE</div>
        <div className="titlebar-button-container">
          <div className="titlebar-button" id="titlebar-minimize" onClick={minimize}>
            <img src="https://api.iconify.design/mdi:window-minimize.svg?color=%23ffffff" alt="minimize" />
          </div>
          <div className="titlebar-button" id="titlebar-maximize" onClick={maximize}>
            <img src="https://api.iconify.design/mdi:window-maximize.svg?color=%23ffffff" alt="maximize" />
          </div>
          <div className="titlebar-button" id="titlebar-close" onClick={close}>
            <img src="https://api.iconify.design/mdi:close.svg?color=%23ffffff" alt="close" />
          </div>
        </div>
      </div>
      {tree && <ComponentsBuilder component={tree} />}
    </div>
  );
};

export default App;
