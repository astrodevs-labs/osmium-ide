import React, {useState} from 'react';

interface LabelProps {
  label: string;
  onLabelClick?: (event: React.MouseEvent<HTMLLabelElement>) => void;
}

const Label: React.FC<LabelProps> = ({
  label,
  onLabelClick,
}) => {
  return (
    <label
      className={'label__input'}
      onClick={onLabelClick}
    >
      {label}
    </label>
  );
};

export default Label;
