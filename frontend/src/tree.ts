import { NodeType } from './builder/ComponentsBuilder';

export const tree: NodeType = {
  id: '1',
  type: 'root',
  properties: [],
  children: [
    {
      id: '2',
      type: 'sidebar',
      properties: [
        {
          name: 'align',
          value: 'left',
        },
      ],
      children: [
        {
          id: '3',
          type: 'sidebar-item',
          properties: [
            {
              name: 'title',
              value: 'Files',
            },
            {
              name: 'icon',
              value: 'file',
            },
          ],
          children: [],
        },
      ],
    },
    {
      id: '4',
      type: 'canvas',
      properties: [],
      children: [],
    },
  ],
};

export const tree2: NodeType = {
  id: '1',
  type: 'root',
  properties: [],
  children: [
    {
      id: '2',
      type: 'sidebar',
      properties: [
        {
          name: 'align',
          value: 'left',
        },
      ],
      children: [
        {
          id: '3',
          type: 'sidebar-item',
          properties: [
            {
              name: 'title',
              value: 'Files',
            },
            {
              name: 'icon',
              value: 'file',
            },
          ],
          children: [],
        },
        {
          id: '5',
          type: 'sidebar-panel',
          properties: [
            {
              name: 'expanded',
              value: true,
            },
          ],
          children: [
            {
              id: '6',
              type: 'file-hierarchy',
              properties: [
                {
                  name: 'files',
                  value: [
                    {
                      name: 'index.html',
                      type: 'html',
                    },
                    {
                      name: 'style.css',
                      type: 'css',
                    },
                    {
                      name: 'script.js',
                      type: 'js',
                    },
                    {
                      name: 'folder1',
                      type: 'folder',
                      items: [
                        {
                          name: 'index.html',
                          type: 'html',
                        },
                        {
                          name: 'style.css',
                          type: 'css',
                        },
                        {
                          name: 'script.js',
                          type: 'js',
                        },
                        {
                          name: 'folder2',
                          type: 'folder',
                          items: [
                            {
                              name: 'index.html',
                              type: 'html',
                            },
                            {
                              name: 'style.css',
                              type: 'css',
                            },
                            {
                              name: 'script.js',
                              type: 'js',
                            },
                          ],
                        },
                      ],
                    },
                  ],
                },
              ],
              children: [],
            },
          ],
        },
      ],
    },
    {
      id: '4',
      type: 'canvas',
      properties: [],
      children: [],
    },
  ],
};

export const tree3: NodeType = {
  id: '1',
  type: 'root',
  properties: [],
  children: [
    {
      id: '2',
      type: 'sidebar',
      properties: [
        {
          name: 'align',
          value: 'left',
        },
      ],
      children: [
        {
          id: '3',
          type: 'sidebar-item',
          properties: [
            {
              name: 'title',
              value: 'Files',
            },
            {
              name: 'icon',
              value: 'file',
            },
          ],
          children: [],
        },
        {
          id: '5',
          type: 'sidebar-panel',
          properties: [
            {
              name: 'expanded',
              value: true,
            },
          ],
          children: [
            {
              id: '6',
              type: 'file-hierarchy',
              properties: [
                {
                  name: 'files',
                  value: [
                    {
                      name: 'index.html',
                      type: 'html',
                    },
                    {
                      name: 'style.css',
                      type: 'css',
                    },
                    {
                      name: 'script.js',
                      type: 'js',
                    },
                    {
                      name: 'folder1',
                      type: 'folder',
                      items: [
                        {
                          name: 'index.html',
                          type: 'html',
                        },
                        {
                          name: 'style.css',
                          type: 'css',
                        },
                        {
                          name: 'script.js',
                          type: 'js',
                        },
                        {
                          name: 'folder2',
                          type: 'folder',
                          items: [
                            {
                              name: 'index.html',
                              type: 'html',
                            },
                            {
                              name: 'style.css',
                              type: 'css',
                            },
                            {
                              name: 'script.js',
                              type: 'js',
                            },
                          ],
                        },
                      ],
                    },
                  ],
                },
              ],
              children: [],
            },
          ],
        },
      ],
    },
    {
      id: '4',
      type: 'canvas',
      properties: [],
      children: [
        {
          id: '7',
          type: 'tabs-bar',
          properties: [],
          children: [
            {
              id: '8',
              type: 'tab',
              properties: [
                {
                  name: 'title',
                  value: 'index.html',
                },
                {
                  name: 'active',
                  value: true,
                },
              ],
              children: [],
            },
            {
              id: '9',
              type: 'tab',
              properties: [
                {
                  name: 'title',
                  value: 'style.css',
                },
                {
                  name: 'active',
                  value: false,
                },
              ],
              children: [],
            },
            {
              id: '10',
              type: 'tab',
              properties: [
                {
                  name: 'title',
                  value: 'script.js',
                },
                {
                  name: 'active',
                  value: false,
                },
              ],
              children: [],
            },
          ],
        },
        {
          id: '11',
          type: 'editor',
          properties: [
            {
              name: 'content',
              value: 'b64 encoded file content',
            },
          ],
          children: [],
        },
      ],
    },
  ],
};
