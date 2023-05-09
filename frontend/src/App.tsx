import { useState } from 'react';
import { Button, Icon, Folder } from './components/Components';

const data = {
  name: 'osmiumide',
  isFolder: true,
  items: [
    {
      name: 'index.html',
      isFolder: false,
      items: [],
    },
    {
      name: 'components',
      isFolder: true,
      items: [
        {
          name: 'Button',
          isFolder: true,
          items: [
            {
              name: 'Button.tsx',
              isFolder: false,
              items: [],
            },
            {
              name: 'Button.css',
              isFolder: false,
              items: [],
            },
          ],
        },
      ],
    },
  ],
};

const App = () => {
  const [content, setContent] = useState<string>('');
  return (
    <div className="w-full h-screen">
      <div className="grid grid-cols-3 gap-4">
        <Button>1</Button>
        <Button disabled>2</Button>
        <Icon icon={'arrow-up'} size={64} color="white" />
        <Icon icon={'arrow-down'} size={64} color="white" />
        <Folder name={data.name} isFolder={data.isFolder} items={data.items} />
      </div>
    </div>
  );
};

export default App;
