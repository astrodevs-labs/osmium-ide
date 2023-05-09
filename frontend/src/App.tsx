import Toolbar from './components/Toolbar/Toolbar';
import { useState } from 'react';
import { Button, Icon, Folder } from './components/Components';
import Card from './components/Card/Card';

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
      <Toolbar content={'test'} setContent={setContent} />
      <br />
      <div className="grid grid-cols-3 gap-4">
        <Button>1</Button>
        <Button disabled>2</Button>
        <Icon icon={'arrow-up'} size={64} color="white" />
        <Icon icon={'arrow-down'} size={64} color="white" />
      </div>
      <br />
      <Card title="Card title" subtitle="Card subtitle">
        <div>Card content</div>
        <Folder name={data.name} isFolder={data.isFolder} items={data.items} />
      </Card>
      <br />
      <Card title="Card title" subtitle="Card subtitle" disabled={true}>
        <div>Card content</div>
        <Folder name={data.name} isFolder={data.isFolder} items={data.items} />
      </Card>
    </div>
  );
};

export default App;
