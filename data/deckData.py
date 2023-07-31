import json
with open('data/ImgPathDatas/Cards.json', "r") as jfile:
    path_data = json.load(fp=jfile)

x = []
for data in path_data:
    for i in range(data["max_value"]):
        suit = data["suit"]
        match suit:
            case "Sword" | "Gun" | "Shield":
                num = 1 if i > 2 else 3
            case "Move" | "Star":
                num = 1 if i > 1 else 2
            case "Chance" | "Curse" | "HpPluse":
                num = 1
        deck_data = {
            "suit" : data["suit"],
            "value": i + 1,
            "num": num
        }
        x.append(deck_data.copy())
with open('data/deckData.json', "w") as jf:
    jf.write(json.dumps(x, indent = '\t'))
