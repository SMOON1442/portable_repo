return {
    {
        "ellisonleao/gruvbox.nvim",
        lazy = false,
        name = "gruvbox",
        priority = 997,
        opts = {
            transparent_mode = true,
        },
        config = function(_, opts)
            require("gruvbox").setup(opts)
            vim.cmd.colorscheme("gruvbox")

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
    },
}

--return {
--    "AlphaTechnolog/pywal.nvim",
--    lazy = false,
--    priority = 1000,
--    config = function()
--        -- Set up pywal and load the colors
--       require("pywal").setup()
--
--  end,
--}

