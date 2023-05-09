import React from 'react';

export interface CardProps {
  children?: React.ReactNode;
  className?: string;
  onClick?: () => void;
  disabled?: boolean;
  visible?: boolean;
  title?: string;
  subtitle?: string;
}
