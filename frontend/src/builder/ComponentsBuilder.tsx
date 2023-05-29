import React, { JSX } from 'react';
import { Button, LeftBar } from '../components/Components';
import Card from '../components/Card/Card';

interface StateType {
  id: string;
  value: string | number | boolean;
}
interface DataType {
  type: string;
  id: string;
  state: StateType[];
}
interface ElementType {
  data: DataType;
  children: ElementType[];
}

const componentTypes = {
  button: Button,
  sidebar: LeftBar,
};

const ComponentsBuilder: React.FC<ElementType> = ({ data, children }) => {
  // @ts-ignore
  const Component = componentTypes[data.type];

  // transform state array to object
  const state = data.state.reduce((acc: any, curr: StateType) => {
    acc[curr.id] = curr.value;
    return acc;
  }, {});

  console.log(state);

  if (Component === undefined) {
    console.error(`Failed to load component with type ${data.type}`);
    return (
      <div id={data.id} {...state}>
        {children.map((child) => (
          <ComponentsBuilder data={child.data} children={child.children} key={child.data.id} />
        ))}
      </div>
    );
  }
  return (
    <Component id={data.id} {...state}>
      {children.map((child) => (
        <ComponentsBuilder data={child.data} children={child.children} key={child.data.id} />
      ))}
    </Component>
  );
};

export default ComponentsBuilder;
