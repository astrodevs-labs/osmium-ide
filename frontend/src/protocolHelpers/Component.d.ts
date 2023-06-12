import { Property } from "./Property";

export type ComponentId = string;

export type Component = {
    id: ComponentId;
    type: string;
    props: Property[];
    children: Component[];
}