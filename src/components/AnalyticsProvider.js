import { inject } from "@vercel/analytics";
import { useEffect } from "react";

export function AnalyticsProvider() {
  useEffect(() => {
    inject();
  }, []);

  return null;
}
