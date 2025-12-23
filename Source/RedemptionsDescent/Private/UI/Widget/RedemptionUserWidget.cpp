// Copyright RedemptionStudios


#include "UI/Widget/RedemptionUserWidget.h"

void URedemptionUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
