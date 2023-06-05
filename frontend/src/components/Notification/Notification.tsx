import { NotificationProps } from './Notification.types';
import React from 'react';

const Status = {
  success: 'bg-osmium-success',
  error: 'bg-osmium-error',
  warning: 'bg-osmium-warning',
  info: 'bg-osmium-primary',
};

const Notification: React.FC<NotificationProps> = ({ status }) => {
  return (
    <div className="fixed bottom-10 right-0">
      <div className="h-full text-white flex flex-row">
        <div className="bg-[#1F272E] w-60 h-20 px-5 py-2 rounded-l-lg">
          <h1 className="flex flex-row-reverse">Title</h1>
          <h1 className="flex flex-row-reverse text-[#727272]">description</h1>
        </div>
        <div className={`${Status[status]} w-2 h-20 rounded-r-lg`} />
      </div>
    </div>
  );
};

export default Notification;
