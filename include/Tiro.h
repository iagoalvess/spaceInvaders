#ifndef TIRO_H
#define TIRO_H

#include "ObjetoJogo.h"
#include "VariaveisGlobais.h"

class Tiro : public ObjetoJogo {

private:
	ObjetoJogo* _origem;

public:

	Tiro(ObjetoJogo* origem);

	void initVelocidade();

	ObjetoJogo* getOrigem();

	void mover();
};

#endif 