# App Launch Optimisation Modules to Breakdown

## Understanding the Modules

1. Linking Module: This is responsible for storing the parameters from the deeplink and the screen the deeplink tells you to go to. It just does the job of storing.

2. App Config Module: This is responsible for storing the app config based on the linking modules parameters. It just does the job of storing.

3. Navigation Module: This is responsible for setting up navigators and all the related navigation logic. It figures out the screens based on the app config and the linking modules parameters.

With these 3 modules, we will be able to create a clearer and deterministic flow of events.

## Linking Module

This is a new module that we are creating. This module is responsible for:

1. Identifying the screen and parameters from the deeplink.
2. Setting the parameters like utm parameters and any other parameters from the deeplink.
3. Exporting static config that can be used by other modules.

## App Config Module

This is a new module that we are creating. This module is responsible for:

1. Storing the app config based on the linking modules parameters.
2. Storing static config.
3. Merge static config and server driven configs.

## Navigation Module

This is a new module that we are creating. This module is responsible for:

1. Setting up navigators and all the related navigation logic.
2. Figuring out the screens based on the app config and the linking modules parameters.
3. Figuring out the first screen based on the app config and the linking modules parameters.

## Launch Manager Module
