import React, { FC } from 'react';

interface RootProps {
  children?: React.ReactNode;
}

const Root: FC<RootProps> = ({ children }) => {
  return <div className="w-full h-full fixed flex">{children}</div>;
};

export default Root;
