import React from 'react';

export interface CheckBoxProps {
  label: string;
  checked: boolean;
  disabled?: boolean;
  onCheckboxChange?: (event: React.ChangeEvent<HTMLInputElement>) => void;
  onCheckboxClick?: (event: React.MouseEvent<HTMLInputElement>) => void;
  onCheckboxFocus?: (event: React.FocusEvent<HTMLInputElement>) => void;
  onCheckboxBlur?: (event: React.FocusEvent<HTMLInputElement>) => void;
}
