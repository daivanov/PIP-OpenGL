/*
 * Copyright 2012 Daniil Ivanov <daniil.ivanov@gmail.com>
 *
 * This file is part of PIP-OpenGL.
 *
 * PIP-OpenGL is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * PIP-OpenGL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with PIP-OpenGL. If not, see http://www.gnu.org/licenses/.
 */

#ifndef CURVEFITTER_H
#define CURVEFITTER_H

typedef struct {
    int refCount;
} View;

/* Constructor */
View *view_init(int argc, char **argv);

/* Run event loop */
void view_run(View *view);

/* Destructor */
View *deinit_view(View *view);

#endif

