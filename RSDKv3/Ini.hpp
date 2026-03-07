#ifndef INI_H
#define INI_H

#if RETRO_PLATFORM != RETRO_PS3
#include <vector>
#endif

class IniParser
{
public:
    enum ItemType {
        INI_ITEM_STRING,
        INI_ITEM_INT,
        INI_ITEM_FLOAT,
        INI_ITEM_BOOL,
        INI_ITEM_COMMENT,
    };

    struct ConfigItem {
        ConfigItem();
        char section[0x20];
        bool hasSection;
        char key[0x40];
        char value[0x100];
        byte type;
    };

    IniParser();
    IniParser(const char *filename, bool addPath = true);

    int GetString(const char *section, const char *key, char *dest);
    int GetInteger(const char *section, const char *key, int *dest);
    int GetFloat(const char *section, const char *key, float *dest);
    int GetBool(const char *section, const char *key, bool *dest);
    int SetString(const char *section, const char *key, char *value);
    int SetInteger(const char *section, const char *key, int value);
    int SetFloat(const char *section, const char *key, float value);
    int SetBool(const char *section, const char *key, bool value);
    int SetComment(const char *section, const char *key, const char *comment);
    void Write(const char *filename, bool addPath = true);

#if RETRO_PLATFORM == RETRO_PS3
    ConfigItem items[512];
    int itemCount;
    int size() { return itemCount; }
#else
    std::vector<ConfigItem> items;
#endif
};
#endif // !INI_H
