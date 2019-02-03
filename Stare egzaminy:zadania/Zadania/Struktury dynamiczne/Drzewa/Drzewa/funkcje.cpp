#include "funkcje.hpp"

void odbij ( wezel * pRoot );

void wypiszWszerz ( wezel * pRoot );

wezel * znajdzNastepnik ( wezel * pRoot , wezel * pPoprzednik );

void usunWezel ( wezel * & pRoot , wezel * pDoUsuniecia );

void rotacja_w_lewo (wezel * & pRoot , wezel * q);

void rotacja_w_prawo (wezel * & pRoot , wezel * p);

#endif /* funkcje_hpp */
