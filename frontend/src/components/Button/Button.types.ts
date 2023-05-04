import React from "react";

export interface ButtonProps {
    onClick?: () => void
    disabled?: boolean
    children?: React.ReactNode
}