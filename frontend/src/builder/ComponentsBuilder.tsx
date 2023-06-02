import React from 'react';
import { Button, Sidebar, SidebarItem, SidebarPanel } from '../components/Components';

interface PropertyType {
  name: string;
  value: any;
}
export interface NodeType {
  id: string;
  type: string;
  properties: PropertyType[];
  children: NodeType[];
}

const componentTypes = {
  button: Button,
  sidebar: Sidebar,
  'sidebar-item': SidebarItem,
  'sidebar-panel': SidebarPanel,
};

const ComponentsBuilder: React.FC<{ node: NodeType }> = ({ node }) => {
  console.log(node);
  // @ts-ignore
  const Component = componentTypes[node.type];
  const state = node.properties.reduce((acc: any, curr: PropertyType) => {
    acc[curr.name] = curr.value;
    return acc;
  }, {});

  if (Component === undefined) {
    console.error(`Failed to load component with type ${node.type}`);
    return (
      <div id={node.id} {...state}>
        {node.children.map((child) => (
          <ComponentsBuilder node={child} key={child.id} />
        ))}
      </div>
    );
  }
  return (
    <Component id={node.id} {...state}>
      {node.children.map((child) => (
        <ComponentsBuilder node={child} key={child.id} />
      ))}
    </Component>
  );
};

export default ComponentsBuilder;
