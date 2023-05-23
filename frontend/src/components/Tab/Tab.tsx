import { TabProps } from './Tab.types';
import { FC, useState } from 'react';

const Tab: FC<TabProps> = ({ file, onClick, active }) => {
  const [hover, setHover] = useState<boolean>(false);
  return (
    <div
      className="relative h-10 bg-osmium-bgCode text-center text-osmium-text pt-2 pr-4 pl-4"
      onMouseOver={() => {
        setHover(true);
      }}
      onMouseOut={() => {
        setHover(false);
      }}
      onClick={onClick}
    >
      <h1 className="select-none">{file}</h1>
      {active ? (
        <div className="bg-osmium-primary w-full h-1 absolute bottom-0 left-0" />
      ) : hover ? (
        <div className="bg-osmium-bgLight w-full h-1 absolute bottom-0 left-0" />
      ) : (
        <div className="w-0" />
      )}
    </div>
  );
};

export default Tab;
