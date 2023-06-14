import React from 'react';
import {
  Button,
  Canvas,
  FileHierarchy,
  Sidebar,
  SidebarItem,
  SidebarPanel,
  Root,
  TabsBar,
  Tab,
  Editor,
} from '../components/Components';
import { Property } from '../protocolHelpers/Property';
import { Component } from '../protocolHelpers/Component';

// interface PropertyType {
//   name: string;
//   value: any;
// }
// export interface NodeType {
//   id: string;
//   type: string;
//   properties: PropertyType[];
//   children: NodeType[];
// }

const componentTypes = {
  button: Button,
  sidebar: Sidebar,
  'sidebar-item': SidebarItem,
  'sidebar-panel': SidebarPanel,
  'file-hierarchy': FileHierarchy,
  canvas: Canvas,
  root: Root,
  'tabs-bar': TabsBar,
  tab: Tab,
  editor: Editor,
};

const ComponentsBuilder: React.FC<{ component: Component | null }> = ({ component }) => {
  console.log(component);
  // @ts-ignore
  const Component = componentTypes[component.type];
  const state = component?.props.reduce<Object>((acc: Object, curr: Property) => {
    acc[curr.name] = curr.value;
    return acc;
  }, {});

  if (Component === undefined) {
    console.error(`Failed to load component with type ${component?.type}`);
    return (
      <div id={component?.id} {...state}>
        {component?.children.map((child) => (
          <ComponentsBuilder component={child} key={child.id} />
        ))}
      </div>
    );
  }
  return (
    <Component id={component?.id} {...state}>
      {component?.children.map((child) => (
        <ComponentsBuilder component={child} key={child.id} />
      ))}
    </Component>
  );
};

export default ComponentsBuilder;
