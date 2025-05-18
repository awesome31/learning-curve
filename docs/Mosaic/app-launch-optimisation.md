# App Launch Optimisation

## Stores and Status

1. userAttributeStore
   - It has fcmToken, deviceInfo, utmSource and params.
   - Remove and make it a part of the userStore.
2. useAppConfigStore
   - Do not remove.
3. useAppLogoStore
   - It has logoUrl, logoWidth and logoHeight.
   - Remove and make it a part of appConfig.
4. useUserPreferenceStore
   - It has the language selected by the user.
   - Remove and make it a part of userStore.
5. useAppLaunchStore
   - Remove and create local state.
6. useLinkStore
   - Create new store with resolvedDeeplinkParams.
7. useNavigationStore
   - Create new store for navigation related data.
8. useStatusBarStore
   - It has isExtendedHeader and statusBarColor.
   - Remove and make it a part of useNavigationStore.

## Navigation Module

This will contain all the logic related to navigation.

1. NavigationContainer.
2. useCurrentScreen.
3. RootStackMount.
4. useNavigationStore

## Plan of Action

1. Create separate modules for user, appConfig and deeplink.
2. All logic related to these modules should be inside the specific folder.

## Future things

1. Deeplink full documentation with screens.
2. Remove async storage from the project.
3. Need to add testing for modules that have a lot of business logic.
