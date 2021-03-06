/*
  File: GdbServerCreate.cpp

  This file is part of the Epiphany Software Development Kit.

  Copyright (C) 2013 Adapteva, Inc.
  See AUTHORS for list of contributors.
  Support e-mail: <support@adapteva.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program (see the file COPYING).  If not, see
  <http://www.gnu.org/licenses/>.
*/


#include "GdbServerSC.h"
#include "targetCntrlHardware.h"

extern unsigned PORT_BASE_NUM;

void *CreateGdbServer(void *ptr)
{
	unsigned *port = (unsigned int *) ptr;

	unsigned coreNum = (*port) - PORT_BASE_NUM;

	TargetControl *tCntrl;
		tCntrl = new TargetControlHardware(coreNum);

	GdbServerSC *rspServerP = new GdbServerSC(*port);

	//cerr << "Thread id " << pthread_self() << endl << flush;

	rspServerP->rspServer(tCntrl);

	return NULL;
}
