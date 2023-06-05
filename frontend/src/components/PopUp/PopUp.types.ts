import React from 'react';

export interface PopUpProps {
  setIsVisible: React.Dispatch<React.SetStateAction<boolean>>;
  status: 'success' | 'error' | 'warning' | 'info';
}
