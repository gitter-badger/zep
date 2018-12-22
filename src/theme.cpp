#include "theme.h"
#include "editor.h"
#include "syntax.h"

namespace Zep
{

ZepTheme::ZepTheme()
{
    double golden_ratio_conjugate = 0.618033988749895;
    double h = .4f;
    for (int i = 0; i < 10; i++)
    {
        h += golden_ratio_conjugate;
        h = std::fmod(h, 1.0);
        m_uniqueColors.emplace_back(HSVToRGB(float(h) * 360.0f, 0.6f, 200.0f));
    }
    SetThemeType(ThemeType::Dark);
}

void ZepTheme::SetThemeType(ThemeType type)
{
    m_currentTheme = type;
    switch(type)
    {
    default:
    case ThemeType::Dark:
        SetDarkTheme();
        break;
    case ThemeType::Light:
        SetLightTheme();
        break;
    }
}

ThemeType ZepTheme::GetThemeType() const
{
    return m_currentTheme;
}

void ZepTheme::SetDarkTheme()
{
    m_colors[ThemeColor::Text] = NVec4f(1.0f);
    m_colors[ThemeColor::Background] = NVec4f(0.1f, 0.1f, 0.1f, 1.0f);
    m_colors[ThemeColor::HiddenText] = NVec4f(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::TabBorder] = NVec4f(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::Tab] = NVec4f(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TabActive] = NVec4f(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::LineNumberBackground] = NVec4f(.13f, .13f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumber] = NVec4f(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumberActive] = NVec4f(.13f, 1.0f, .13f, 1.0f);
    m_colors[ThemeColor::CursorNormal] = NVec4f(130.0f / 255.0f, 140.0f / 255.0f, 230.0f / 255.0f, 1.0f);
    m_colors[ThemeColor::CursorInsert] = NVec4f(1.0f, 1.0f, 1.0f, .9f);
    m_colors[ThemeColor::CursorLineBackground] = NVec4f(.15f, .15f, .15f, 1.0f);
    m_colors[ThemeColor::AirlineBackground] = NVec4f(.12f, .12f, .12f, 1.0f);
    m_colors[ThemeColor::Light] = NVec4f(1.0f);
    m_colors[ThemeColor::Dark] = NVec4f(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::VisualSelectBackground] = NVec4f(.47f, 0.30f, 0.25f, 1.0f);
    m_colors[ThemeColor::Mode] = NVec4f(.2f, 0.8f, 0.2f, 1.0f);

    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Comment] = NVec4f(0.0f, 1.0f, .1f, 1.0f);
    m_colors[ThemeColor::Keyword] = NVec4f(0.1f, 1.0f, 1.0f, 1.0f);
    m_colors[ThemeColor::Integer] = NVec4f(0.1f, 1.0f, 1.0f, 1.0f);
    m_colors[ThemeColor::Whitespace] = NVec4f(0.15f, .2f, .15f, 1.0f);
}

void ZepTheme::SetLightTheme()
{
    m_colors[ThemeColor::Text] = NVec4f(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::Background] = NVec4f(.9f, .9f, .9f, 1.0f);
    m_colors[ThemeColor::HiddenText] = NVec4f(.9f, .1f, .1f, 1.0f);
    m_colors[ThemeColor::TabBorder] = NVec4f(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::Tab] = NVec4f(.4f, .4f, .4f, .55f);
    m_colors[ThemeColor::TabActive] = NVec4f(.55f, .55f, .55f, 1.0f);
    m_colors[ThemeColor::LineNumberBackground] = NVec4f(.87f, .87f, .87f, 1.0f);
    m_colors[ThemeColor::LineNumber] = NVec4f(.13f, .5f, .13f, 1.0f);
    m_colors[ThemeColor::LineNumberActive] = NVec4f(.13f, 0.6f, .13f, 1.0f);
    m_colors[ThemeColor::CursorNormal] = NVec4f(130.0f / 255.0f, 140.0f / 255.0f, 230.0f / 255.0f, 1.0f);
    m_colors[ThemeColor::CursorInsert] = NVec4f(1.0f, 1.0f, 1.0f, .9f);
    m_colors[ThemeColor::CursorLineBackground] = NVec4f(.85f, .85f, .85f, 1.0f);
    m_colors[ThemeColor::AirlineBackground] = NVec4f(.87f, .87f, .87f, 1.0f);
    m_colors[ThemeColor::Light] = NVec4f(1.0f);
    m_colors[ThemeColor::Dark] = NVec4f(0.0f, 0.0f, 0.0f, 1.0f);
    m_colors[ThemeColor::VisualSelectBackground] = NVec4f(.49f, 0.60f, 0.45f, 1.0f);
    m_colors[ThemeColor::Mode] = NVec4f(.2f, 0.8f, 0.2f, 1.0f);

    m_colors[ThemeColor::Normal] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Parenthesis] = m_colors[ThemeColor::Text];
    m_colors[ThemeColor::Comment] = NVec4f(0.1f, .4f, .1f, 1.0f);
    m_colors[ThemeColor::Keyword] = NVec4f(0.1f, .2f, .4f, 1.0f);
    m_colors[ThemeColor::Integer] = NVec4f(0.1f, .4f, .2f, 1.0f);
    m_colors[ThemeColor::Whitespace] = NVec4f(0.15f, .2f, .15f, 1.0f);
}
NVec4f ZepTheme::GetUniqueColor(uint32_t index) const
{
    return m_uniqueColors[index % m_uniqueColors.size()];
}

NVec4f ZepTheme::GetColor(ThemeColor themeColor) const
{
    auto itr = m_colors.find(themeColor);
    if (itr == m_colors.end())
    {
        return NVec4f(1.0f);
    }
    return itr->second;
}

NVec4f ZepTheme::GetComplement(const NVec4f& col) const
{
    auto lum = Luminosity(col);
    if (lum > 0.5f)
        return GetColor(ThemeColor::Dark);
    return GetColor(ThemeColor::Light);
}

} // namespace Zep
