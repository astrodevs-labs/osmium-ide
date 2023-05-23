import Toolbar from './components/Toolbar/Toolbar';
import { useState } from 'react';
import {
  Button,
  CheckBox,
  Folder,
  Icon,
  LeftBar,
  Notification,
  PopUp,
  Switch,
  TabsBar,
  TextArea,
} from './components/Components';
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
  const [textAreaIsVisible, setTextAreaIsVisible] = useState<boolean>(false);
  const [popUpIsVIsible, setpopUpIsVIsible] = useState<boolean>(false);
  const [notificationIsVIsible, setNotificationIsVIsible] = useState<boolean>(false);
  return (
    <div className="w-full h-screen">
      <Toolbar content={'test'} setContent={setContent} />
      <div className="w-full h-full flex row">
        <LeftBar></LeftBar>
        <div className="w-full h-full">
          <TabsBar
            fileList={[
              'teseeeet.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
              'test2.sol',
              'teseeeeet3.sol',
            ]}
          />
          <br />
          <div className="grid grid-cols-3 gap-4">
            <Button>1</Button>
            <Button disabled>2</Button>
            <Button
              onClick={() => {
                setTextAreaIsVisible(!textAreaIsVisible);
              }}
            >
              TextArea
            </Button>
            <Button
              onClick={() => {
                setpopUpIsVIsible(!popUpIsVIsible);
              }}
            >
              popup
            </Button>
            <Button
              onClick={() => {
                setNotificationIsVIsible(!notificationIsVIsible);
              }}
            >
              notification
            </Button>
            <Icon icon={'arrow-up'} size={64} fill="white" viewBox="0 0 1024 1024" />
            <Icon icon={'arrow-down'} size={64} fill="white" viewBox="0 0 1024 1024" />
          </div>
          <br />
          {textAreaIsVisible ? (
            <TextArea content={content} setContent={setContent} />
          ) : (
            <>
              <Card title="Card title" subtitle="Card subtitle">
                <div>Card content</div>
                <Folder name={data.name} isFolder={data.isFolder} items={data.items} />
              </Card>
              <br />
              <Card title="Card title" subtitle="Card subtitle" disabled={true}>
                <div>Card content</div>
                <Folder name={data.name} isFolder={data.isFolder} items={data.items} />
              </Card>
              <CheckBox label={'test'} checked={false} />
              <Switch
                onClick={() => {
                  console.log('onClick');
                }}
                disabled
              />
              {popUpIsVIsible ? <PopUp setIsvisible={setpopUpIsVIsible} color="bg-osmium-error" /> : null}
              {notificationIsVIsible ? <Notification color="bg-osmium-error" /> : null}
            </>
          )}
        </div>
      </div>
    </div>
  );
};

export default App;
