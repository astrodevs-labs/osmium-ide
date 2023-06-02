import { FC, useState } from 'react';

interface TabProps {
  title: string;
  active: boolean;
}

const Tab: FC<TabProps> = ({ title, active }) => {
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
      onClick={() => {
        console.log('click');
      }}
    >
      <h1 className="select-none">{title}</h1>
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
