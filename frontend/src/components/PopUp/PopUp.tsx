import React from 'react';
import { PopUpProps } from './PopUp.types';

const Status = {
  success: 'bg-osmium-success',
  error: 'bg-osmium-error',
  warning: 'bg-osmium-warning',
  info: 'bg-osmium-primary',
};

const PopUp: React.FC<PopUpProps> = ({ setIsVisible, status }) => {
  return (
    <div className="fixed pt-24 left-0 top-0 w-full h-full overflow-auto">
      <div className="bg-osmium-border relative m-auto p-0 w-2/5 rounded-lg border-osmium-bgLight border-2">
        <div className="flex flex-row justify-between items-center">
          <h2 className="text-osmium-text font-bold px-1">Title</h2>
          <div
            onClick={() => setIsVisible(false)}
            className="text-osmium-text px-2 text-3xl hover:text-osmium-grey no-underline cursor-pointer"
          >
            &times;
          </div>
        </div>
        <div className="bg-osmium-bgLight h-0.5"></div>
        <p className="text-osmium-bgLight h-16 px-1">Description de test ...</p>
        <div className={`${Status[status]} h-1 rounded-lg`}></div>
      </div>
    </div>
  );
};

export default PopUp;
