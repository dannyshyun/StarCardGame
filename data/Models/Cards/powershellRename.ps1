
Get-ChildItem *.mv1 -Filter "*Ace*" | ForEach{Rename-Item $_ -NewName $_.Name.Replace("Ace", "1")}
Get-ChildItem *.mv1 -Filter "*Jack*" | ForEach{
    Rename-Item $_ -NewName $_.Name.Replace("Sword", "Chance")
    Rename-Item $_ -NewName $_.Name.Replace("Gun", "Curse")
    Rename-Item $_ -NewName $_.Name.Replace("Shield", "Heart")
    Rename-Item $_ -NewName $_.Name.Replace("Star", "Move")
    Rename-Item $_ -NewName $_.Name.Replace("Jack", "1")
}
Get-ChildItem *.mv1 -Filter "*Queen*" | ForEach{
    Rename-Item $_ -NewName $_.Name.Replace("Sword", "Chance")
    Rename-Item $_ -NewName $_.Name.Replace("Gun", "Curse")
    Rename-Item $_ -NewName $_.Name.Replace("Shield", "Heart")
    Rename-Item $_ -NewName $_.Name.Replace("Star", "Move")
    Rename-Item $_ -NewName $_.Name.Replace("Queen", "2")
}
Get-ChildItem *.mv1 -Filter "*King*" | ForEach{
    Rename-Item $_ -NewName $_.Name.Replace("Sword", "Chance")
    Rename-Item $_ -NewName $_.Name.Replace("Gun", "Curse")
    Rename-Item $_ -NewName $_.Name.Replace("Shield", "Heart")
    Rename-Item $_ -NewName $_.Name.Replace("Star", "Move")
}
Get-ChildItem *.mv1 -Filter "*King*" | ForEach{
    Rename-Item $_ -NewName $_.Name.Replace("King", "3")
}
cmd /c 'pause'