import React, { FC } from 'react';

interface SidebarPanelProps {
  children?: React.ReactNode;
}

const SidebarPanel: FC<SidebarPanelProps> = ({ children }) => {
  return <div>{children}</div>;
};

export default SidebarPanel;
