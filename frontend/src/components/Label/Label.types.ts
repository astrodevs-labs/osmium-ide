import React from 'react';

export interface LabelProps {
  label: string;
  onLabelClick?: (event: React.MouseEvent<HTMLLabelElement>) => void;
}
