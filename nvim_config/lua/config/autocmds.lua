vim.api.nvim_create_autocmd("ColorScheme", {
  pattern = "gruvbox",
  callback = function()
    local groups = {
      "Normal",
      "NormalNC",
      "SignColumn",
      "EndOfBuffer",
      "NormalFloat",
      "FloatBorder",
    }

    for _, group in ipairs(groups) do
      vim.api.nvim_set_hl(0, group, { bg = "NONE" })
    end
  end,
})
