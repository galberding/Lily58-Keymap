# Lily58-Keymap

## Quick setup 

- setup and build
```
python3 -m pip install qmk
export QMK_HOME=$(pwd) 
qmk setup 
git clone git@github.com:galberding/Lily58-Keymap.git keyboards/lily58/keymaps/gag
```

- flash

```
qmk flash -kb lily58 -km gag
```
