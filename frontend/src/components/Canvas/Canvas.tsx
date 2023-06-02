import React, { FC } from 'react';

interface CanvasProps {
  children?: React.ReactNode;
}

const Canvas: FC<CanvasProps> = ({ children }) => {
  return <div className="w-full h-full">{children}</div>;
};

export default Canvas;
