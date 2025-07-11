bool isIsomorphic(char* s, char* t) {
    unsigned char mapS[256] = {0};
    unsigned char mapT[256] = {0};

    for (int i = 0; s[i] != '\0'; ++i) {
        unsigned char sc = s[i];
        unsigned char tc = t[i];

        if (mapS[sc] == 0 && mapT[tc] == 0) {
            mapS[sc] = tc;
            mapT[tc] = sc;
        } else {
            if (mapS[sc] != tc || mapT[tc] != sc)
                return false;
        }
    }

    return true;
}
