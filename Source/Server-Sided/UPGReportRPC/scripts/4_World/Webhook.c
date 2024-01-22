class DiscordWebhook
{
    string username;
    string avatar_url;
    string content;
    ref array<ref DiscordEmbed> embeds;

    void AddEmbed(DiscordEmbed embed)
    {
        if (!embeds)
            embeds = new array<ref DiscordEmbed>();

        embeds.Insert(embed);
    }
}

class DiscordEmbed
{
    string title;
    string description;
    int color;
    ref DiscordServer server;
    ref array<ref DiscordField> fields;
    string timestamp;

    void AddField(DiscordField field)
    {
        if (!fields)
            fields = new array<ref DiscordField>();

        fields.Insert(field);
    }

    void SetServer(string servername)
    {
        server = new DiscordServer();
        server.server = servername;
    }
}

class DiscordField
{
    string name;
    string value;
    bool inline;
}

class DiscordServer
{
    string server;
}
