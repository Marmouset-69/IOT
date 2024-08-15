# How to set ON/OFF a group of notifications

Add the following commands to "config.yaml"
``` config.yaml 
ios:
  actions:
    - name: alarm_maison
      label:
        text: "Alarm Maison"
      icon:
        icon: home_export_outline
        color: "#ffffff"
      show_in_carplay: false
      show_in_watch: true
```
