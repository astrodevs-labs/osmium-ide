import { appWindow } from '@tauri-apps/api/window';
import ComponentsBuilder from './builder/ComponentsBuilder';

document.getElementById('titlebar-minimize')?.addEventListener('click', () => appWindow.minimize());
document.getElementById('titlebar-maximize')?.addEventListener('click', () => appWindow.toggleMaximize());
document.getElementById('titlebar-close')?.addEventListener('click', () => appWindow.close());

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
  return (
    // the app must be in a full height and width div flexed to center the app
    <div className="h-full w-full">
      <ComponentsBuilder data={data.windows[0].elements.root.data} children={data.windows[0].elements.root.children} />
    </div>
  );
};

export default App;
