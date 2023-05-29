import { appWindow } from '@tauri-apps/api/window';
import ComponentsBuilder from './builder/ComponentsBuilder';

const data = {
  windows: [
    {
      elements: {
        root: {
          data: {
            type: 'root',
            id: '1',
            state: [
              {
                id: 'prop1',
                value: 'value1',
              },
              {
                id: 'prop2',
                value: 2,
              },
            ],
          },
          children: [
            {
              data: {
                type: 'sidebar',
                id: '2',
                state: [
                  {
                    id: 'collapsed',
                    value: true,
                  },
                ],
              },
              children: [],
            },
            {
              data: {
                type: 'button',
                id: '3',
                state: [
                  {
                    id: 'value',
                    value: 'HEY',
                  },
                ],
              },
              children: [],
            },
            {
              data: {
                type: 'button',
                id: '4',
                state: [
                  {
                    id: 'value',
                    value: 'test',
                  },
                  {
                    id: 'disabled',
                    value: 'true',
                  },
                ],
              },
              children: [],
            },
          ],
        },
      },
    },
  ],
};

const App = () => {
  const minimize = () => {
    appWindow.minimize();
  };

  const maximize = () => {
    appWindow.isMaximized().then((maximized) => {
      if (maximized) {
        appWindow.unmaximize();
      } else {
        appWindow.maximize();
      }
    });
  };

  const close = () => {
    appWindow.close();
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
      <ComponentsBuilder data={data.windows[0].elements.root.data} children={data.windows[0].elements.root.children} />
    </div>
  );
};

export default App;
